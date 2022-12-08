#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'000'010
#define double long double
#define f first
#define s second
#define eps 1e-11
#define pb push_back
#define MAXN 1123

int dil[MAXN];
int dic[MAXN];

int cl[MAXN][MAXN];
int cc[MAXN][MAXN];

int mt[MAXN][MAXN];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(5);
    cout.setf(ios::fixed);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mt[i][j];
        }
    }

    for(int i=0;i<n;i++){
        set<int> s;
        for(int j=0;j<m;j++)s.insert(mt[i][j]);
        map<int,int> ma;
        int curr=1;
        dil[i]=s.size();
        while(s.size()>0){
            ma[*s.begin()]=curr;
            curr++;
            s.erase(*s.begin());
        }
        for(int j=0;j<m;j++)cl[i][j]=ma[mt[i][j]];
    }
    for(int j=0;j<m;j++){
        set<int> s;
        for(int i=0;i<n;i++)s.insert(mt[i][j]);
        map<int,int> ma;
        int curr=1;
        dic[j]=s.size();
        while(s.size()>0){
            ma[*s.begin()]=curr;
            curr++;
            s.erase(*s.begin());
        }
        for(int i=0;i<n;i++)cc[i][j]=ma[mt[i][j]];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int h=max(cl[i][j],cc[i][j]);
            cout<<max(dil[i]+h-cl[i][j],dic[j]+h-cc[i][j])<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}