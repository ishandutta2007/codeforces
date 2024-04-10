#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define S second
#define F first
#define mp make_pair
ll x;
int n,d;
ll mod = 1e9+7;
ll getX()
{
    x = (x*37+10007)%mod;
    return x;
}
const int N = 2e5+100;
int a[N];
int b[N],c[N];
vector<int> ones;
void pre()
{
    for(int i = 0;i<n;i++)a[i] = i+1;
    for(int i = 0;i<n;i++) swap(a[i],a[getX()%(i+1)]);
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getX() % (i + 1)]);
    }    
    for(int i = 0;i<n;i++) if(b[i]) ones.push_back(i);
}
pair<int,int> P[N];
set<int> undone; vector<int> toerase;
int main()
{
    // n=100000,d=2000,x=1;
    cin>>n>>d>>x;
    pre();
    for(int i = 0;i<n;i++) P[i] = make_pair(a[i],i),undone.insert(i);
    srand(time(0));    
    random_shuffle(P,P+n);    
    sort(P,P+n,greater<pair<int,int> >());
    for(int i = 0;i<n;i++)
    {
        toerase.clear();
        int pos = P[i].S, val = P[i].F;
        if(undone.size() >= d)
        {
            for(int j: ones){
                if(pos+j < n && !c[pos+j]) c[pos+j] = val, undone.erase(pos+j);
                if(pos + j >=n) break;
            }
            continue;
        }
        for(int ind:undone){
           if(ind >= pos && b[ind-pos]) c[ind] = val, toerase.push_back(ind); 
        }
        for(int x:toerase) undone.erase(x);
    }
    for(int i = 1;i<=n;i++) printf("%d\n",c[i-1]);
}