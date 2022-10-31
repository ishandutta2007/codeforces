#pragma GCC optimize("O0")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5+7;
pair<ll,ll> A[N];
int Check(pair<ll,ll> &a,pair<ll,ll> &b,pair<ll,ll> &c){
    ll area = (b.first-a.first)*(a.second+b.second)+(c.first-b.first)*(b.second+c.second)+(a.first-c.first)*(a.second+c.second);
    if (area>0)
        return 1;
    if (area<0)
        return -1;
    return 0;
}
ll dist(pair<ll,ll> &a,pair<ll,ll> &b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
struct triangle{
    ll len1,len2,len3,area;
    triangle(pair<ll,ll> &a,pair<ll,ll> &b,pair<ll,ll> &c){
        len1 = dist(a,b);
        len2 = dist(b,c);
        len3 = dist(c,a);
        area = (b.first-a.first)*(a.second+b.second)+(c.first-b.first)*(b.second+c.second)+(a.first-c.first)*(a.second+c.second);
    }
};
vector<triangle> build_hull(pair<ll,ll> *A,int n){
    sort(A+1,A+1+n);
    vector<pair<ll,ll> > hull;
    for(int i = 1;i<=n;++i){
        while(hull.size()>=2){
            if (Check(hull[hull.size()-2],hull[hull.size()-1],A[i])!=1)
                hull.pop_back();
            else break;
        }
        hull.push_back(A[i]);
    }
    int sz = hull.size();
    for(int i = n-1;i>=1;--i){
        while(hull.size()>sz){
            if (Check(hull[hull.size()-2],hull[hull.size()-1],A[i])!=1)
                hull.pop_back();
            else break;
        }
        hull.push_back(A[i]);
    }

    vector<triangle> ret;
    if ((hull.size()-1)<3)
        return ret;
    hull.push_back(hull[1]);
    sz = hull.size()-2;
    for(int i = 0;i<sz;++i){
        ret.push_back(triangle(hull[i],hull[i+1],hull[i+2]));
    }
    return ret;
}
const bool operator == (const triangle &a,const triangle &b){
    return a.len1==b.len1 && a.len2==b.len2 && a.len3==b.len3 && a.area==b.area;
}
const bool operator != (const triangle &a,const triangle &b){
    return !(a==b);
}

void unite(vector<triangle> &ret,vector<triangle> &a,vector<triangle> &b){
    for(auto to:a)
        ret.push_back(to);
    triangle aa = a[0];
    aa.len1 = aa.len2 = aa.len3 = aa.area = -1;
    ret.push_back(aa);
    for(auto to:b)
        ret.push_back(to);
    for(auto to:b)
        ret.push_back(to);
}
int dp[N*3];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
    }

    vector<triangle> hull1 = build_hull(A,n);
    ll len1 = dist(A[1],A[n]);
    for(int i = 1;i<=m;++i)
        cin>>A[i].first>>A[i].second;
    vector<triangle> hull2 = build_hull(A,m);
    ll len2 = dist(A[1],A[m]);
    if (hull1.size()!=hull2.size()){
        cout<<"NO\n";
        return 0;
    }
    if (hull1.empty() && hull2.empty()){
        cout<<(len1==len2?"YES\n":"NO\n");
        return 0;
    }
    vector<triangle> kmp;
    unite(kmp,hull1,hull2);
    int sz = kmp.size();
    for(int i = 1;i<sz;++i){
        dp[i] = dp[i-1];
        while(dp[i]-1>0 && kmp[dp[i]]!=kmp[i]){
            dp[i] = dp[dp[i]-1];
        }
        if (kmp[dp[i]]==kmp[i])
            ++dp[i];
        if (dp[i]==hull1.size() && i-dp[i]+1>=dp[i]){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";

    return 0;
}