#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n;
int p[Maxn+5];
int to_r[Maxn+5][2];
int u_val[Maxn+5],u_r[Maxn+5][2],d_val[Maxn+5],d_r[Maxn+5][2];
int pos_r[Maxn+5];
int qu[2][Maxn+5],qu_f[2],qu_t[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		pos_r[i]=n+1;
	}
	u_val[n]=0,u_r[n][0]=u_r[n][1]=n;
	d_val[n]=n+1,d_r[n][0]=d_r[n][1]=n;
	to_r[n][0]=to_r[n][1]=n+1;
	for(int i=n-1;i>0;i--){
		if(p[i]<p[i+1]){
			to_r[i][0]=to_r[i+1][0],to_r[i][1]=i;
			u_val[i]=u_val[i+1],u_r[i][0]=u_r[i+1][0],u_r[i][1]=u_r[i+1][1];
			d_val[i]=p[i+1],d_r[i][0]=i;
			for(int j=to_r[i][0]-1;j<=n;j++){
				if(j+1>n){
					d_r[i][1]=n;
					break;
				}
				if(p[j]<p[j+1]){
					continue;
				}
				if(p[i]>p[j+1]){
					if(p[j]<d_val[j+1]){
						d_r[i][1]=d_r[j+1][1];
					}
					else{
						d_r[i][1]=d_r[j+1][0];
					}
				}
				else{
					d_r[i][1]=j;
				}
				break;
			}
		}
		else{
			to_r[i][1]=to_r[i+1][1],to_r[i][0]=i;
			d_val[i]=d_val[i+1],d_r[i][0]=d_r[i+1][0],d_r[i][1]=d_r[i+1][1];
			u_val[i]=p[i+1],u_r[i][0]=i;
			for(int j=to_r[i][1]-1;j<=n;j++){
				if(j+1>n){
					u_r[i][1]=n;
					break;
				}
				if(p[j]>p[j+1]){
					continue;
				}
				if(p[i]<p[j+1]){
					if(p[j]>u_val[j+1]){
						u_r[i][1]=u_r[j+1][1];
					}
					else{
						u_r[i][1]=u_r[j+1][0];
					}
				}
				else{
					u_r[i][1]=j;
				}
				break;
			}
		}
	}
	qu_f[0]=1,qu_t[0]=0;
	for(int i=1;i<=n;i++){
		while(qu_f[0]<=qu_t[0]&&p[qu[0][qu_f[0]]]<p[i]){
			pos_r[qu[0][qu_f[0]]]=std::min(pos_r[qu[0][qu_f[0]]],i);
			qu_f[0]++;
		}
		if(p[i]>p[i+1]){
			while(qu_f[0]<=qu_t[0]&&p[qu[0][qu_t[0]]]>p[i]){
				qu_t[0]--;
			}
			qu[0][++qu_t[0]]=i;
		}
	}
	qu_f[1]=1,qu_t[1]=0;
	for(int i=1;i<=n;i++){
		while(qu_f[1]<=qu_t[1]&&p[qu[1][qu_f[1]]]>p[i]){
			pos_r[qu[1][qu_f[1]]]=std::min(pos_r[qu[1][qu_f[1]]],i);
			qu_f[1]++;
		}
		if(p[i]<p[i+1]){
			while(qu_f[1]<=qu_t[1]&&p[qu[1][qu_t[1]]]<p[i]){
				qu_t[1]--;
			}
			qu[1][++qu_t[1]]=i;
		}
	}
	for(int i=n-1;i>0;i--){
		pos_r[i]=std::min(pos_r[i+1],pos_r[i]);
	}
	ll ans=0;
	qu_f[0]=1,qu_t[0]=0,qu_f[1]=1,qu_t[1]=0;
	for(int i=1,j=1;i<=n;i++){
		if(pos_r[i]==n+1){
			ans+=n-i+1;
			continue;
		}
		while(qu_f[0]<=qu_t[0]&&qu[0][qu_f[0]]<i){
			qu_f[0]++;
		}
		while(qu_f[1]<=qu_t[1]&&qu[1][qu_f[1]]<i){
			qu_f[1]++;
		}
		while(j<pos_r[i]){
			if(p[j]>p[j+1]){
				while(qu_f[0]<=qu_t[0]&&p[qu[0][qu_t[0]]]>p[j]){
					qu_t[0]--;
				}
				qu[0][++qu_t[0]]=j;
			}
			else{
				while(qu_f[1]<=qu_t[1]&&p[qu[1][qu_t[1]]]<p[j]){
					qu_t[1]--;
				}
				qu[1][++qu_t[1]]=j;
			}
			j++;
		}
		int r=pos_r[i];
		int mn_r,mx_l;
		if(qu_f[0]>qu_t[0]){
			mn_r=n+1;
		}
		else{
			mn_r=p[qu[0][qu_f[0]]];
		}
		if(qu_f[1]>qu_t[1]){
			mx_l=0;
		}
		else{
			mx_l=p[qu[1][qu_f[1]]];
		}
		if(p[r-1]>p[r]){
			if(mx_l<d_val[r]){
				r=d_r[r][1];
			}
			else{
				r=d_r[r][0];
			}
		}
		else{
			if(mn_r>u_val[r]){
				r=u_r[r][1];
			}
			else{
				r=u_r[r][0];
			}
		}
		ans+=r-i+1;
	}
	printf("%lld\n",ans);
	return 0;
}