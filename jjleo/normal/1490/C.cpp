#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll x;
set<ll> st;

int main(){
	scanf("%d", &t);
	for(ll i = 1;i * i * i <= 1e12;i++) st.insert(i * i * i);
	while(t--){
		scanf("%lld", &x);
		bool tag = false;
		for(set<ll>::iterator it = st.begin();it != st.end() && !tag;++it){
			if(st.find(x - *it) != st.end()) tag = true;
		}
		puts(tag ? "YES" : "NO");
	}
}