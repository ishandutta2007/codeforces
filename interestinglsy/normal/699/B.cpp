#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;  
  
char s[1005][1005];  
  
int main()  
{  
    int n,m;  
    while(cin>>n>>m)  
    {  
        for(int i=0;i<n;i++)  
        {  
            scanf("%s",s[i]);  
        }  
        int x1=-1,y1=-1,x2=-1,y2=-1;   //x1.y1A1x2.y2A2  
        int k=-1;  
        int flag1=0;  
        for(int j=0;j<n;j++)  
        {  
            for(int i=0;i<m;i++)  
            {  
                if(s[j][i]=='*')  
                {  
                    x1=j;  
                    y1=i;  
                    k=j;  
                    flag1=1;  
                    break;  
                }  
            }  
            if(flag1==1) break;  
        }  
        flag1=0;  
        for(int j=k+1;j<n;j++)  
        {  
            for(int i=0;i<m;i++)  
            {  
                if(s[j][i]=='*'&&i!=y1)  
                {  
                    x2=j;  
                    y2=i;  
                    flag1=1;  
                    break;  
                }  
            }  
            if(flag1==1) break;  
        }  
        if(x1==-1)   //A1,,11  
        {  
            cout<<"YES"<<endl;  
            cout<<"1 1"<<endl;  
        }  
        else if(x2==-1)   //A2,A1A1  
        {  
            cout<<"YES"<<endl;  
            cout<<x1+1<<" "<<y1+1<<endl;  
        }  
        else  
        {  
            int x=x1,y=y2;  
            int flag=0;  
            for(int i=0;i<n;i++)  
            {  
                for(int j=0;j<m;j++)  
                {  
                    if(s[i][j]=='*'&&i!=x&&j!=y)     
                    {  
                        flag=1;  
                        break;  
                    }  
                }  
                if(flag==1) break;  
            }  
            if(flag==0)  
            {  
                cout<<"YES"<<endl;  
                cout<<x+1<<" "<<y+1<<endl;  
            }  
            else  
            {  
                x=x2,y=y1;  
                flag=0;  
                for(int i=0;i<n;i++)  
                {  
                    for(int j=0;j<m;j++)  
                    {  
                        if(s[i][j]=='*'&&i!=x&&j!=y)  
                        {  
                            flag=1;  
                            break;  
                        }  
                    }  
                    if(flag==1) break;  
                }  
                if(flag==0)  
                {  
                    cout<<"YES"<<endl;  
                    cout<<x+1<<" "<<y+1<<endl;  
                }  
                else  
                {  
                    cout<<"NO"<<endl;  
                }  
            }  
        }  
    }  
    return 0;  
}