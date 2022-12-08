#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define MAXN 212345
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double

int n;

int resp[51][51];
int resp2[51][51];

bool ask(int i1,int j1,int i2,int j2){
    i1++;j1++;i2++;j2++;
    cout<<"? "<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
    int ans;
    cin>>ans;
    return ans;
}

bool isval(int i,int j){
    return i>=0&&j>=0&&i<n&&j<n;
}

bool askme(int i1,int j1,int i2,int j2,int var){
    if(!isval(i2,j2))return 0;
    if(var==0){
        if(i2==i1+2){
            return resp[i1][j1]==resp[i2][j2]&&
            (resp[i1+1][j1]==resp[i1+2][j1]||resp[i1][j1+1]==resp[i1+1][j1+1]);
        }
        else{
            return resp[i1][j1]==resp[i2][j2]&&
            (resp[i1][j1+1]==resp[i1][j1+2]||resp[i1+1][j1]==resp[i1+1][j1+1]);
        }
    }
    else{
        if(i2==i1+2){
            return resp2[i1][j1]==resp2[i2][j2]&&
            (resp2[i1+1][j1]==resp2[i1+2][j1]||resp2[i1][j1+1]==resp2[i1+1][j1+1]);
        }
        else{
            return resp2[i1][j1]==resp2[i2][j2]&&
            (resp2[i1][j1+1]==resp2[i1][j1+2]||resp2[i1+1][j1]==resp2[i1+1][j1+1]);
        }
    }
}

void answer(bool x){
    if(x==0){
        cout<<"!\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<resp[i][j];
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"!\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<resp2[i][j];
            }
            cout<<"\n";
        }
    }
    cout.flush();
    exit(0);
}

int32_t main(){


    cin>>n;

    int at=0;

    while(at<n){
        if(at!=0&&at!=n-1){
            resp[at][at]=!(resp[at-1][at-1]^ask(at-1,at-1,at,at));
        }
        else resp[at][at]=1;
        for(int i=at;i+2<n;i+=2){
            resp[at][i+2]=!(resp[at][i]^ask(at,i,at,i+2));
        }
        for(int i=at;i+2<n;i+=2){
            resp[i+2][at]=!(resp[i][at]^ask(i,at,i+2,at));
        }
        at++;
    }
    resp[n-1][n-1]=0;
    at=0;
    while(at+1<n){
        if(at!=0){
            resp[at][at+1]=!(resp[at-1][at]^ask(at-1,at,at,at+1));
        }
        else resp[at][at+1]=1;
        for(int i=at+1;i+2<n;i+=2){
            resp[at][i+2]=!(resp[at][i]^ask(at,i,at,i+2));
        }
        for(int i=at;i+2<n;i+=2){
            resp[i+2][at+1]=!(resp[i][at+1]^ask(i,at+1,i+2,at+1));
        }
        at++;
    }
    resp[1][0]=!(resp[1][2]^ask(1,0,1,2));
    for(int i=3;i<n;i+=2){
        resp[i][0]=!(resp[i-2][0]^ask(i-2,0,i,0));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2==0)resp2[i][j]=resp[i][j];
            else resp2[i][j]=!resp[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<"hora da vdd"<<endl;

            bool p1=askme(i,j,i+2,j+1,0);
            bool p2=askme(i,j,i+2,j+1,1);
            if(p1!=p2){
                bool resp=ask(i,j,i+2,j+1);
                if(resp==p1)answer(0);
                else answer(1);
            }
            p1=askme(i,j,i+1,j+2,0);
            p2=askme(i,j,i+1,j+2,1);
            if(p1!=p2){
                bool resp=ask(i,j,i+1,j+2);
                if(resp==p1)answer(0);
                else answer(1);
            }
        }
    }


    return 0;
}