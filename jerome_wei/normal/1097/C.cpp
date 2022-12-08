#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
char x[6000010];
int l[N],r[N],minsz[N];
int lst[N];
map<int, vector<int> >MP;
bool cmp(const int a,const int b){
	return minsz[a] < minsz[b];
}
int ch[N];
int n;
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%s",x+1);
		int len=strlen(x+1);
		int cur=0;
		for(int j=1;j<=len;j++){
			if(x[j]=='(')l[i]++,cur++;
			else r[i]++,cur--;
			minsz[i]=min(minsz[i],cur);
		}
		lst[i]=cur;
		MP[lst[i]].push_back(i);
	}
	int ans=0;
	map<int,vector<int> > ::iterator itt;
	for(itt=MP.begin();itt!=MP.end();itt++){
		int x=( *itt ).first;vector<int> S=(*itt).second;
		//cout<<x<<endl;
		if(x<0)continue;
		sort(S.begin(),S.end());
		if(MP.find(-x)==MP.end())continue;
		vector<int> S2=MP[-x];
		sort(S2.begin(),S2.end(),cmp);
		int j=S2.size()-1;
		
		for(size_t i=0;i<S.size();i++)if(minsz[S[i]]>=0&&!ch[S[i]]){
			if(i==j && x==0) j--;
			while(j>=0&&ch[S2[j]])j--;
			
			while(j>=0 && minsz[S2[j]]+lst[S[i]] >=0 ) {
				if(S[i]==S2[j]||ch[S2[j]]){
					j--;continue;
				}
				ch[S[i]]=ch[S2[j]]=1;
				ans++,j--;break;
			}
		}
	}
	cout << ans << endl;
}