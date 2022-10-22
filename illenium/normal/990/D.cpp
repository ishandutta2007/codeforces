#include<iostream>
using namespace std;

int n,a,b,count=1;
int edge[1005][1005];

int main()
{
    cin>>n>>a>>b;
    if(a!=1 && b!=1)
	{
        cout<<"NO"; 
        return 0;
    }

    if(a!=1)
	{
        a--;
        while(a--)
		{
            for(int i=1;i<=n;i++) edge[count][i]=edge[i][count]=0;
            count++; 
        }
        for(int i=count+1;i<=n;i++) edge[count][i]=edge[i][count]=1;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
		{
            for(int j=1;j<=n;j++) cout<<edge[i][j];
            cout<<endl;
        }
        return 0;
    }
    if(b!=1)
	{
        b--;
        while(b--)
		{
            for(int i=1;i<=n;i++) edge[count][i]=edge[i][count]=0;
            count++; 
        }
        for(int i=count+1;i<=n;i++) edge[count][i]=edge[i][count]=1;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
		{
            for(int j=1;j<=n;j++)
			{
                if( i==j ) cout<<0;
                else cout<<!edge[i][j];
            }
            cout<<endl;
        }
        return 0;
    }
    
    if(a==1 && b==1 && n>=4)
	{
        int connect=1;
        for(int i=2;i<=n;i++)
		{
            edge[connect][i]=edge[i][connect]=1;
            connect=i;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<edge[i][j];
            cout<<endl;
        }    
        return 0;
    }
    
    if(a==1 && b==1)
	{
        if(n==1) cout<<"YES"<<endl<<0;
        else cout<<"NO";
    }
    return 0;
}