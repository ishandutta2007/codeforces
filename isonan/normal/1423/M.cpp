#include <cstdio>
#include <vector>

int n,m;
typedef std::vector<int>vec;
vec r,c;
int stk[1000001],pos[1000001],top,map[101][101];
int get(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	int x;
#ifdef ISONAN
	x=map[i][j];
#else
	scanf("%d",&x);
#endif
	return x;
}
vec solve(vec r,vec c){
	if(r.size()>=c.size()){
		vec fin;
		if(r.size()==1){
			int L=0,R=c.size()-1;
			int p=0,mn=0x7f7f7f7f;
			for(int j=L;j<=R;j++){
				int x=get(r[0],c[j]);
				if(x<mn)mn=x,p=j;
			}
			fin.push_back(p);
			fin.push_back(mn);
			return fin;
		}
		vec tem;
		for(int i=0;i<r.size();i+=2)tem.push_back(r[i]);
		vec ans=solve(tem,c);
		int fmn=ans.back();
		for(int i=0;i<r.size();i++)
			if(i&1){
				int L=ans[i>>1],R=(i+1<r.size())?ans[(i+1)>>1]:(c.size()-1);
				int p=0,mn=0x7f7f7f7f;
				for(int j=L;j<=R;j++){
					int x=get(r[i],c[j]);
					if(x<mn)mn=x,p=j;
				}
				fin.push_back(p);
				fmn=std::min(fmn,mn);
			}
			else fin.push_back(ans[i>>1]);
		fin.push_back(fmn);
		return fin;
	}
	else{
		top=0;
		for(int i=0;i<c.size();i++){
			while(top){
				if(get(r[pos[top]],c[stk[top]])<=get(r[pos[top]],c[i])){
					if(pos[top]+1<r.size()){
						stk[++top]=i;
						pos[top]=pos[top-1]+1;
					}
					break;
				}
				else{
					--top;
				}
			}
			if(!top){
				stk[++top]=i;
				pos[top]=0;
			}
		}
		vec tem;
		for(int i=1;i<=top;i++)tem.push_back(c[stk[i]]);
		vec ans=solve(r,tem);
		for(int i=0,j=0;i+1<ans.size();i++){
			while(c[j]<tem[ans[i]])++j;
			ans[i]=j;
		}
		return ans;
	}
}
int main(){
	scanf("%d%d",&n,&m);
#ifdef ISONAN
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
#endif
	for(int i=1;i<=n;i++)r.push_back(i);
	for(int i=1;i<=m;i++)c.push_back(i);
	printf("! %d",solve(r,c).back());
	fflush(stdout);
	return 0;
}