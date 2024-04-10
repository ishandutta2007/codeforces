    #include<bits/stdc++.h>
    #define ll long long
    #define pii pair<int,int>
    #define fi first
    #define se second
    using namespace std;
    const int mod=1e9+7;
    const int S=1<<21;
    int n;
    int a[S],c[S],d[S];
    pii b[S];
    void change(int x,int y){
    	if(y>b[x].fi)b[x].se=b[x].fi,b[x].fi=y;
    	else if(y>b[x].se)b[x].se=y;
    }
    int main(){
    	scanf("%d",&n);
    	for(int i=0;i<S;++i)d[i]=n+1;
    	for(int i=1;i<=n;++i){
    		scanf("%d",&a[i]);
    		change(a[i],i);
    	}
    	for(int k=1;k<S;k<<=1){
    		for(int i=0;i<S;i+=k<<1){
    			for(int j=0;j<k;++j){
    				change(i+j,b[i+j+k].fi);
    				change(i+j,b[i+j+k].se);
    			}
    		}
    	}
    	for(int i=0;i<S;++i){
    		c[i]=b[i].se;
    	}
    	for(int k=1;k<S;k<<=1){
    		for(int i=0;i<S;i+=k<<1){
    			for(int j=0;j<k;++j){
    				c[i+j]=max(c[i+j],c[i+j+k]);
    			}
    		}
    	}
    	int ans=0;
    	for(int i=1;i<=n;++i){
    		int s=0;
    		for(int j=20;j>=0;--j){
    			if(a[i]>>j&1)continue;
    			if(c[s^(1<<j)]>i)s|=1<<j;
    		}
    		if(c[0]>i)ans=max(ans,a[i]^s);
    	}
    	printf("%d\n",ans);
    	return 0;
    }