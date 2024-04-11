    #include <bits/stdc++.h>
    using namespace std;
    long long a[100001],tmp;
    int n,v[100001],ma[100001],m,o,l,r,k;
    long long ask(int p){
    	tmp=0;
    	for(;p;p-=(p&(-p)))tmp+=a[p];
    	return tmp;
    }
    void add(int p,int x){
    	for(;p<=n;p+=(p&(-p))){
    		a[p]+=x;
    		ma[p]=v[p];
            for(int i=1;i<(p&(-p));i<<=1)ma[p]=max(ma[p],ma[p-i]);
    	}
    }
    int main(){
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++){
    		scanf("%d",&v[i]);
    		ma[i]=a[i]=v[i];
    		k=((i&(-i))>>1);
    		for(;k;k>>=1){
    			a[i]+=a[i-k];
    			ma[i]=max(ma[i],ma[i-k]);
    		}
    	}
    	while(m--){
    		scanf("%d%d%d",&o,&l,&r);
    		if(o==1){
    			printf("%lld\n",ask(r)-ask(l-1));
    			continue;
    		}
    		if(o==2){
    			scanf("%d",&o);
    			for(int j=r;j>=l;j--){
    				if(ma[j]<o){
    					j=j-(j&(-j))+1;
    					continue;
    				}
    				if(v[j]>=o){
    					k=v[j];
    					v[j]%=o;
    					add(j,v[j]-k);
    				}
    			}
    		}
    		else{
    			k=v[l];
    			v[l]=r;
    			add(l,r-k);
    		}
    	}
    	return 0;
    }