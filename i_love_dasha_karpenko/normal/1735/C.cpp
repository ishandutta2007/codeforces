#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 40;
int P[N];
int F(int x){
	return x==P[x]?x:P[x] = F(P[x]);
}
void unite(int a,int b){
	a = F(a);
	b = F(b);
	P[a] = b;
}
void solve(){
	int n;
	cin>>n;
	set<char> S;
	for(int i = 0;i<26;i+=1){
		S.insert(char('a'+i));
	}
	for(int i = 1;i<=26;i+=1){
		P[i] = i;
	}
	map<char,char> M;
	for(int i = 1;i<=n;i+=1){
		char ch;
		cin>>ch;
		if (M.count(ch)){
			cout<<M[ch];
		}
		else{
			for(char to:S){
				if (to==ch || (F(to-'a'+1)==F(ch-'a'+1) && S.size()>1)){
					continue;
				}
				M[ch] = to;
				unite(to-'a'+1,ch-'a'+1);
				S.erase(to);
				break;
			}
			cout<<M[ch];
		}
	}
	cout<<endl;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}