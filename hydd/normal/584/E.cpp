/*********************************************************************
 * Source
 * ProblemCF584E
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<utility>
#include<vector>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef pair<int,int> pii;
int n,a[2100],b[2100],pos[2100],ans2;
vector<pii> ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]),a[i]--;
	for (int i=0;i<n;i++) scanf("%d",&b[i]),b[i]--,pos[b[i]]=i;
	for (int i=0;i<n;i++){
		int x;
		for (int j=i;j<n;j++)
			if (a[j]==b[i]) x=j;
		for (int j=x-1;j>=i;j--) 
			if (pos[a[j]]>=x){
				ans.push_back(pii(x,j));
				ans2+=x-j;
				swap(a[x],a[j]); x=j;
			}
	}
	printf("%d %d\n",ans2,(int)ans.size());
	for (auto x:ans) printf("%d %d\n",x.first+1,x.second+1);
	return 0;
}