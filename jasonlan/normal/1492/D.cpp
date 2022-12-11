    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    using namespace std;
    const int maxn=201000;
    int a,b,k;
    int ans1[maxn],ans2[maxn];
    inline int read(){
    	int res=0;
    	char ch=getchar(),ch1=ch;
    	while(!isdigit(ch))ch1=ch,ch=getchar();
    	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    	return ch1==-'-'?-res:res;
    }
    int main(){
    	a=read();b=read();k=read();
    	if(k&&(k>a+b-2||b==1||a==0))puts("NO");
    	else{
    		puts("YES");
    		if(!k){
    			for(int i=1;i<=b;++i)cout<<1;
    			for(int i=1;i<=a;++i)cout<<0;
    			cout<<endl;
    			for(int i=1;i<=b;++i)cout<<1;
    			for(int i=1;i<=a;++i)cout<<0;
    			cout<<endl;
    			return 0;
    		}
    		ans1[1]=0;ans2[1]=1;
    		for(int i=2,flag=1,acnt=a-1;i<a+b;++i){
    			if(i==k+1){
    				flag=0;
    				ans1[i]=1;ans2[i]=0;
    				continue;
    			}
    			else{
    				if(acnt>0)ans1[i]=ans2[i]=0,--acnt;
    				else ans1[i]=ans2[i]=1;
    			}
    		}
    		ans1[a+b]=ans2[a+b]=1;
    		for(int i=a+b;i;--i)cout<<ans1[i];
    		cout<<endl;
    		for(int i=a+b;i;--i)cout<<ans2[i];
    		cout<<endl;
    	}
    	return 0;
    }