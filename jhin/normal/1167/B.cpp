#include <bits/stdc++.h>

using namespace std;
int x;bool vis[10000];int c[6]={4,8,15,42,23,16},a[6],b[6];
int main() {


        cout<<"? 1 2\n"<<flush;
        cin>>x;
        a[0]=x;
        cout<<"? 2 3\n"<<flush;
        cin>>x;
        a[1]=x;
        cout<<"? 3 4\n"<<flush;
        cin>>x;
        a[2]=x;
        cout<<"? 4 5\n"<<flush;
        cin>>x;
        a[3]=x;
        if(a[0]%5==0&&a[1]%5!=0)b[0]=15;
        if(a[0]%5==0&&a[1]%5==0)b[1]=15;
        else if(a[1]%5==0&&a[2]%5==0)b[2]=15;
        else if(a[2]%5==0&&a[3]%5==0)b[3]=15;
        if(a[0]%23==0&&a[1]%23!=0)b[0]=23;
        if(a[0]%23==0&&a[1]%23==0)b[1]=23;
        else if(a[1]%23==0&&a[2]%23==0)b[2]=23;
        else if(a[2]%23==0&&a[3]%23==0)b[3]=23;
        if(a[0]%42==0&&a[1]%42!=0)b[0]=42;
        if(a[0]%42==0&&a[1]%42==0)b[1]=42;
        else if(a[1]%42==0&&a[2]%42==0)b[2]=42;
        else if(a[2]%42==0&&a[3]%42==0)b[3]=42;
        int y,z;
        for(int i=0;i<4;i++)if(b[i])y=i;
        z=y;
        while(z>0)b[z-1]=a[z-1]/b[z],z--;
        z=y;
        while(z<4)b[z+1]=a[z]/b[z],z++;
        for(int i=0;i<5;i++)vis[b[i]]=true;
        for(int i=0;i<6;i++)if(!vis[c[i]])b[5]=c[i];



cout<<"! "<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<" "<<b[5]<<flush;

}