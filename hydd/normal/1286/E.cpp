#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const ll P=1e18;
ll ans1,ans2; int ans26,anss;
int n,lst[1610000],nxt[1610000],w[1610000]; char c;
string s; char tmp[21];
vector<int> st;
map<int,int> cnt;
map<int,int>::iterator it;
void print() {
    if (ans1 == 0) {
        std::cout << ans2 << "\n";
        return;
    }
    std::cout << ans1 << std::setw(18) << std::setfill('0') << ans2 << "\n";
}
int query(int pos){ return w[*std::lower_bound(st.begin(),st.end(),pos)];}
signed main(){
	ios::sync_with_stdio(false);
	scanf("%lld",&n);
	scanf("%s%lld",tmp,&w[0]);
	s+=tmp[0]; ans26=w[0]%26;
	ans2=w[0]; anss=w[0]; st.push_back(0);
	print(); ll sum=0;
	for (int i=1,j=0;i<n;i++){
		scanf("%s%lld",tmp,&w[i]);
		c=(tmp[0]-'a'+ans26)%26+'a'; s+=c;
		w[i]^=anss;
		
		while (j&&c!=s[j]) j=nxt[j];
		if (c==s[j]) j++; nxt[i+1]=j;
		
		if (c==s[nxt[i]]) lst[i]=lst[nxt[i]];
		else lst[i]=nxt[i];
		
		for (int k=i;k;)
			if (c==s[k]) k=lst[k];
			else{
				int v=query(i-k); cnt[v]--;
				sum-=v;
				if (!cnt[v]) cnt.erase(v);
				k=nxt[k];
			}
		if (s[0]==c){
			cnt[w[i]]++;
			sum+=w[i];
		}
		while (!st.empty()&&w[i]<=w[st.back()]) st.pop_back();
		st.push_back(i);
		int now=0;
		while (!cnt.empty()&&(--cnt.end())->first>w[i]){
			it=--cnt.end();
			sum-=1ll*(it->first-w[i])*it->second; now+=it->second;
			cnt.erase(it);
		}
		
		cnt[w[i]]+=now;
		
		ll res=w[st[0]]+sum;
		ans2+=res;
		if (ans2>=P){
			ans2-=P;
			ans1++;
		}
		ans26=(ans26+res)%26;
		anss=(anss+res)&((1<<30)-1);
		print();
	}
	return 0;
}