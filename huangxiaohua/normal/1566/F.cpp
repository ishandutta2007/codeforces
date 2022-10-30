#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[400500],it,x,y;
ll res,f[400500],len[400500],f2[400500];

vector<int> vl[400500],vr[400500];
set<int> st;

struct sb{
	int l,r;
	bool operator<(const sb x)const{return (l<x.l);}
}s[400500];
struct sb2{
	int l,r,id;
	bool operator<(const sb2 x)const{return (r>x.r);}
}s2[400500];

struct sb3{
	ll w,dx;
	bool operator<(const sb3 x)const{return (w>x.w);}
}s3;

struct sb4{
	ll w,dx;
	bool operator<(const sb4 x)const{return (dx>x.dx);}
}s5;
priority_queue<sb2> q2;
priority_queue<sb3> q3,q4;
priority_queue<sb4> q5;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		res=0;it=0;st.clear();
		map<int,int> mp;
		st.insert(1145141919);
		st.insert(-1145141919);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			st.insert(a[i]);
			vl[i].clear();vr[i].clear();
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			mp[a[i]]=i;
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			auto it1=st.upper_bound(y);
			it1--;
			if(*it1>=x&&*it1<=y){continue;}
			s[++it].l=x;s[it].r=y;
			//printf("nmsl%d %d\n",s[it].l,s[it].r);
		}
		for(i=1;i<=n;i++){
			s[++it].l=a[i];
			s[it].r=a[i];
		}
		m=it;
		memset(len,0,m*8+50);
		sort(s+1,s+m+1);
		memset(f,1,m*8+50);
		f2[0]=1e18;
		for(i=1;i<=m;i++){
			s2[i].l=s[i].l;
			s2[i].r=s[i].r;
			s2[i].id=i;
		}
		for(i=1;i<=m;i++){
			auto it1=st.upper_bound(s[i].r);
			k=mp[*it1];
			if(k){
				vl[k].push_back(i);
			}
			it1--;
			k=mp[*it1];
			if(k){
				vr[k].push_back(i);
			}
		}
		int lst=0;
		for(i=1;i<=n;i++){
			while(!q2.empty()){q2.pop();}
			while(!q3.empty()){q3.pop();}
			while(!q4.empty()){q4.pop();}
			while(!q5.empty()){q5.pop();}
			if(i==1){
				int mx=2e9;
				if(vl[1].empty()){q3.push({0,0});q5.push({0,0});}
				else{
					for(auto j:vl[i]){mx=min(mx,s[j].r);}
					mx=a[1]-mx;
					q3.push({mx,mx});
					q5.push({mx,mx});
				}
			}
			else{
				for(auto j:vl[i]){
					q3.push({f[j],len[j]});q5.push({f[j],len[j]});
				}
			}
			if(q3.empty()){
				q3.push({f[lst],0});q5.push({f[lst],0});
			}
			for(auto j:vr[i]){
				q2.push(s2[j]);
			}
			int iit=1;
			for(auto j:vr[i]){
				ll t1,t2,t3;
				if(iit){
					t1=0;
					while(!q5.empty()&&q5.top().dx<=t1){
						q4.push({q5.top().w+q5.top().dx,-1});
						q5.pop();
					}
					t2=t3=1e18;
					if(!q3.empty()){
						t2=q3.top().w+t1+t1;
					}
					if(!q4.empty()){
						t3=q4.top().w+t1;
					}
					t2=min(t2,t3);
					f[j]=t2;
					if(!q2.empty()){
						t1=q2.top().r;
						if(j!=m&&i!=n){
							t1=a[i+1]-t1;
							f[j]+=t1;
							len[j]=t1;
						}
					}
					lst=j;
					iit=0;
				}
				t1=s[j].l-a[i];
				while(!q5.empty()&&q5.top().dx<=t1){
					q4.push({q5.top().w+q5.top().dx,-1});
					q5.pop();
				}
				t2=t3=1e18;
				if(!q3.empty()){
					t2=q3.top().w+t1+t1;
				}
				if(!q4.empty()){
					t3=q4.top().w+t1;
				}
				t2=min(t2,t3);
				f[j]=t2;
				if(i>1||i==n){f[j]=min(f[j],t1+f2[i-1]);}
				while(!q2.empty()){
					if(q2.top().l<=s[j].l){q2.pop();}
					else{break;}
				}
				if(!q2.empty()){
					t1=q2.top().r;
					if(j!=m&&i!=n){
						t1=a[i+1]-t1;
						f[j]+=t1;
						len[j]=t1;
					}
				}
				lst=j;
			}
			f2[i]=f[lst];
		}
		printf("%lld\n",f[m]);
	}
}