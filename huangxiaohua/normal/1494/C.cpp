#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int,bool> mp,mp2;
int i,j,k,n,m,t,L,R,MD,tmp,res1,res2,tmp2,mn,tmp3,tmp4;

vector<int> l,l1,r,r1,l2,r2;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		l.clear();
		r.clear();
		l1.clear();
		r1.clear();
		l2.clear();
		r2.clear();
		mp.clear();
		mp2.clear();
		res1=res2=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k<0){
				l.push_back(-k);mp[-k]=1;
			}
			else{
				r.push_back(k);mp2[k]=1;
			}
		}
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			if(k<0){
				l1.push_back(-k);
				if(mp[-k]){l2.push_back(-k);}
			}
			else{
				r1.push_back(k);
				if(mp2[k]){r2.push_back(k);}
			}
		}
		sort(l.begin(),l.end());
		sort(l1.begin(),l1.end());
		sort(l2.begin(),l2.end());
		
		//for(auto i:l){printf("%d ",i);}puts("");for(auto i:l1){printf("%d ",i);}puts("");for(auto i:l2){printf("%d ",i);}puts("");
		//for(auto i:r){printf("%d ",i);}puts("");for(auto i:r1){printf("%d ",i);}puts("");for(auto i:r2){printf("%d ",i);}puts("");
		res1=l2.size();
		res2=r2.size();
		for(i=0;i<l1.size();i++){
			if(!l.size()){break;}
			
			
			L=1;R=200000;tmp=0;
			while(L<=R){
				MD=(L+R)>>1;
				tmp2=(upper_bound(l.begin(),l.end(),l1[i]-1+MD)-l.begin());
				//printf("a%d %d %d\n",l1[i],l1[i]-1+MD,tmp2);
				if(tmp2==MD){tmp=l1[i]-1+MD;L=MD+1;continue;}
				if(tmp2<MD){R=MD-1;}
				else{L=MD+1;}
			}
			//printf("b%d %d\n",l1[i],tmp);
			
			if(!tmp){continue;}
			tmp3=(upper_bound(l1.begin(),l1.end(),tmp)-l1.begin())-i;
			tmp4=l2.size()-(upper_bound(l2.begin(),l2.end(),tmp+1)-l2.begin());
			
			res1=max(res1,tmp3+tmp4);
			//printf("b%d %d %d %d\n",l1[i],tmp,tmp3,tmp4);
		}
		
		for(i=0;i<r1.size();i++){
			if(!r.size()){break;}
			
			
			L=1;R=200000;tmp=0;
			while(L<=R){
				MD=(L+R)>>1;
				tmp2=(upper_bound(r.begin(),r.end(),r1[i]-1+MD)-r.begin());
				//printf("a%d %d %d\n",r1[i],r1[i]-1+MD,tmp2);
				if(tmp2==MD){tmp=r1[i]-1+MD;L=MD+1;continue;}
				if(tmp2<MD){R=MD-1;}
				else{L=MD+1;}
			}
			//printf("b%d %d\n",r1[i],tmp);
			
			if(!tmp){continue;}
			tmp3=(upper_bound(r1.begin(),r1.end(),tmp)-r1.begin())-i;
			tmp4=r2.size()-(upper_bound(r2.begin(),r2.end(),tmp+1)-r2.begin());
			
			res2=max(res2,tmp3+tmp4);
			//printf("b%d %d %d %d\n",r1[i],tmp,tmp3,tmp4);
		}
		printf("%d\n",res1+res2);
	}
}