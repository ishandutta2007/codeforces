#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> pii;
void output(pii t){printf("%d %d ",t.first,t.second);}
const int N=1e5+5;
vector<pii> ask1,ask2;
char res1[N],res2[N];


inline void query(vector<pii> &ask,char res[]){
	printf("Q %d ",(int)ask.size());
	for(size_t i=0;i<ask.size();i++){
		output(ask[i]);
	}puts("");
	fflush(stdout);
	ask.clear();
	scanf("%s",res);
}

pii blk[N];int colo[N];
int bcnt;
int lst[N],id[N],pos[N];
vector<int> ans[4];
inline void doit(){
	for(int i=1;i<n;i++){
		if(i&1)ask1.push_back(pii(i,i+1));
		else ask2.push_back(pii(i,i+1));
	}
	if(ask1.size())query(ask1,res1);
	if(ask2.size())query(ask2,res2);
	bcnt=1;
	blk[1]=pii(1,1);
	pos[1]=bcnt;
	for(int i=1;i<n;i++){
		int equal = (i&1)?res1[(i-1)/2]:res2[(i-1)/2]; equal -= '0';
		if(!equal)++bcnt,blk[bcnt].first=i+1;
		pos[i+1]=bcnt;
		blk[bcnt].second=i+1;
	}
	lst[1]=lst[2]=0;
	for(int i=1;i+2<=bcnt;i++){
		lst[i+2]=lst[i]^1;
		if(lst[i])ask1.push_back(pii(blk[i].first,blk[i+2].first)),id[i]=ask1.size()-1;
		else ask2.push_back(pii(blk[i].first,blk[i+2].first)),id[i]=ask2.size()-1;
	}
	if(ask1.size())query(ask1,res1);
	if(ask2.size())query(ask2,res2);
	colo[1]=1,colo[2]=2;
	for(int i=1;i+2<=n;i++){
		int equal=lst[i]?res1[id[i]]:res2[id[i]];equal-='0';
		colo[i+2]=equal?colo[i] : 6-colo[i]-colo[i+1];
	}
	for(int i=1;i<=n;i++){
		ans[colo[pos[i]]].push_back(i);
	}
	cout <<"A " << ans[1].size() << " " << ans[2].size() << " " << ans[3].size() << endl;
	for(int i=1;i<=3;i++){
		for(size_t j=0;j<ans[i].size();j++){
			printf("%d ",ans[i][j]);
		}puts("");
		ans[i].clear();
	}
}

int main()
{
	int T;cin >> T;
	while(T--){
		cin >> n;
		doit();
	}
}