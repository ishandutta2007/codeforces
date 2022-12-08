#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define int long long
#define pb push_back
#define inf INT_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

int n;
vector<int> v;
int resp[212345];

bool is_one(){
    int resp=1;
    for(int i=0;i<n;i++){
        if(v[i]==v[(i+1)%n])resp=0;
    }
    return resp;
}

bool is_samee(){
    int resp=1;
    for(int i=0;i<n;i++){
        if(v[i]!=v[0])resp=0;
    }
    return resp;
}

void vai(int i){
    resp[i]=1;
    int ant=1;
    for(int j=(i+1)%n;;j=(j+1)%n){
        if(ant==1){resp[j]=2;ant=2;}
        else{resp[j]=1;ant=1;}
        if(v[j]==v[(j+1)%n])break;
    }
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.pb(x);
        }
        if((n%2) && is_one()){
            //cout<<"entra"<<endl;
            cout<<3<<endl;
            for(int i=0;i<n-1;i++)cout<<(i%2)+1<<" ";
            cout<<3<<" "<<endl;
            continue;
        }
        if(is_one()){
            cout<<2<<endl;
            for(int i=0;i<n;i++)cout<<(i%2)+1<<" ";
            cout<<endl;
            continue;
        }
        if(is_samee()){
            cout<<1<<endl;
            for(int i=0;i<n;i++)cout<<1<<" ";
            cout<<endl;
            continue;
        }
        cout<<2<<endl;
        for(int i=0;i<n;i++){
            if(v[i]==v[(i+1)%n])vai((i+1)%n);
        }
        for(int i=0;i<n;i++)cout<<resp[i]<<" ";
        cout<<endl;

    }

    
    return 0;
 
}