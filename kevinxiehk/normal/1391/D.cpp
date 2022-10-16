#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int arr[8][500005];
int n,m;
int ahh[8][500005];
int aaa(int a){
    int arrt[2][500005];
    bool don[500005];
    for(int i=0;i<m;i++)don[i]=false;
    for(int i=0;i<=1;i++)for(int j=0;j<m-1;j++)arrt[i][j]=ahh[i][j];
    int ans=999999999;
    int t=a;
    for(int i=0;i<m-2;i++){
        if(arrt[0][i]){
            arrt[0][i]=0;
            arrt[0][i+1]^=1;
            t++;
            don[i]=true;
        }
    }
    for(int i=0;i<m-2;i++){
        if(arrt[1][i]){
            arrt[1][i]=0;
            arrt[1][i+1]^=1;
            if(!don[i])t++;
        }
    }
    if(arrt[0][m-2]+arrt[1][m-2])t=999999999;
    return t;
}
int main(){
    cin>>n>>m;
    if(n>=4&&m>=4){cout<<"-1"<<endl;return 0;}
    else if(n==1||m==1){cout<<"0"<<endl;return 0;}
    char c;
    if(n<m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                arr[i][j]=int(c-'0');
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                arr[j][i]=int(c-'0');
            }
        }
        swap(n,m);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int t=(arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i][j+1]+1)%2;
            ahh[i][j]=t;
        }
    }
    if(n==2){
        int ans=999999999;
        int t=0;
        int arrt[m+5];
        for(int i=0;i<m-1;i++){arrt[i]=ahh[0][i];}
        for(int i=0;i<m-2;i++){
            if(arrt[i]){
                arrt[i]=0;
                arrt[i+1]^=1;
                t++;
            }
        }
        if(arrt[m-2])t=999999999;
        ans=min(ans,t);
        for(int i=0;i<m-1;i++)arrt[i]=ahh[0][i];
        t=1;
        arrt[0]^=1;
        for(int i=0;i<m-2;i++){
            if(arrt[i]){
                arrt[i]=0;
                arrt[i+1]^=1;
                t++;
            }
        }
        if(arrt[m-2])t=999999999;
        ans=min(ans,t);
        for(int i=0;i<m-1;i++)arrt[i]=ahh[0][i];
        t=1;
        arrt[m-2]^=1;
        for(int i=0;i<m-2;i++){
            if(arrt[i]){
                arrt[i]=0;
                arrt[i+1]^=1;
                t++;
            }
        }
        if(arrt[m-2])t=999999999;
        ans=min(ans,t);
        for(int i=0;i<m-1;i++)arrt[i]=ahh[0][i];
        t=2;
        arrt[0]^=1;
        arrt[m-2]^=1;
        for(int i=0;i<m-2;i++){
            if(arrt[i]){
                arrt[i]=0;
                arrt[i+1]^=1;
                t++;
            }
        }
        if(arrt[m-2])t=999999999;
        ans=min(ans,t);
        cout<<ans<<endl;
        return 0;
    }
    else{
        int ans=999999999;
        ans=min(ans,aaa(0));
        ahh[0][0]^=1;
        ans=min(ans,aaa(1));
        ahh[0][0]^=1;
        ahh[1][0]^=1;
        ans=min(ans,aaa(1));
        ahh[1][0]^=1;
        ahh[0][m-2]^=1;
        ans=min(ans,aaa(1));
        ahh[0][m-2]^=1;
        ahh[1][m-2]^=1;
        ans=min(ans,aaa(1));
        ahh[1][m-2]^=1;
        ahh[0][0]^=1;
        ahh[1][0]^=1;
        ans=min(ans,aaa(1));
        ahh[1][0]^=1;
        ahh[0][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[0][m-2]^=1;
        ahh[1][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[1][m-2]^=1;
        ahh[0][0]^=1;
        ahh[1][0]^=1;
        ahh[0][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[0][m-2]^=1;
        ahh[1][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[1][m-2]^=1;
        ahh[1][0]^=1;
        ahh[0][m-2]^=1;
        ahh[1][m-2]^=1;
        ans=min(ans,aaa(1));
        ahh[1][m-2]^=1;
        ahh[0][m-2]^=1;
        ahh[0][0]^=1;
        ahh[1][0]^=1;
        ahh[0][m-2]^=1;
        ahh[1][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[0][0]^=1;
        ans=min(ans,aaa(2));
        ahh[0][0]^=1;
        ahh[1][0]^=1;
        ans=min(ans,aaa(2));
        ahh[1][0]^=1;
        ahh[0][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[0][m-2]^=1;
        ahh[1][m-2]^=1;
        ans=min(ans,aaa(2));
        ahh[1][m-2]^=1;
        cout<<ans<<endl;
    }
    return 0;
}