    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    const ll MAXN=1e5+51;
    ll cnt,k,l,r,mid,tmp;
    inline ll read()
    {
        register ll num=0,neg=1;
        register char ch=getchar();
        while(!isdigit(ch)&&ch!='-')
        {
            ch=getchar();
        }
        if(ch=='-')
        {
            neg=-1;
            ch=getchar();
        }
        while(isdigit(ch))
        {
            num=(num<<3)+(num<<1)+(ch-'0');
            ch=getchar();
        }
        return num*neg;
    } 
    inline ll calc(ll eat)
    {
    	ll rem=cnt-eat;
    	return (rem+1)*rem/2;
    }
    int main()
    {
    	cnt=read(),k=read();
    	l=1,r=cnt;
    	while(r-l>10)
    	{
    		mid=(l+r)>>1,tmp=calc(mid);
    		if(tmp<k+mid)
    		{
    			r=mid-1;
    		}
    		else
    		{
    			l=mid;
    		}
    	}
    	for(register int i=l;i<=r;i++)
    	{
    		if(calc(i)==k+i)
    		{
    			cout<<i<<endl;
    			return 0;
    		}
    	}
    	puts("0");
    }