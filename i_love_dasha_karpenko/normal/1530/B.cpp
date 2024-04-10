//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void solve(){
    int h,w;
    cin>>h>>w;
    vector<pair<int,int>> ans1,ans2;
    {

        pair<int, int> vec = {0, 1};
        pair<int, int> cur = {1, 1};
        pair<int, int> last = cur;
        ans1.push_back(cur);
        while(1){
            int x = cur.first+vec.first;
            int y = cur.second+vec.second;
            if (x<1 || x>h || y<1 || y>w || (x==1 && y==1)){
                if (vec==pair<int,int>{0,1})
                    vec = {1,0};
                else if (vec==pair<int,int>{1,0})
                    vec = {0,-1};
                else if (vec==pair<int,int>{0,-1})
                    vec = {-1,0};
                else break;
                continue;
            }
            cur = {x,y};
            if (max(abs(x-last.first),abs(y-last.second))>1 && max(abs(x-1),abs(y-1))>1){
                last = cur;
                ans1.push_back(cur);
            }
        }
    }
    {

        pair<int, int> vec = {0, 1};
        pair<int, int> cur = {1, 2};
        pair<int, int> last = cur;
        ans2.push_back(cur);
        while(1){
            int x = cur.first+vec.first;
            int y = cur.second+vec.second;
            if (x<1 || x>h || y<1 || y>w || (x==1 && y==2)){
                if (vec==pair<int,int>{0,1})
                    vec = {1,0};
                else if (vec==pair<int,int>{1,0})
                    vec = {0,-1};
                else if (vec==pair<int,int>{0,-1})
                    vec = {-1,0};
                else break;
                continue;
            }
            cur = {x,y};
            if (max(abs(x-last.first),abs(y-last.second))>1 && max(abs(x-1),abs(y-2))>1){
                last = cur;
                ans2.push_back(cur);
            }
        }
    }
    if (ans1.size()<ans2.size())
        swap(ans1,ans2);
    sort(ans1.begin(),ans1.end(),greater<pair<int,int>>());
    for(int i = 1;i<=h;++i){
        for(int j = 1;j<=w;++j){
            if (!ans1.empty() && pair<int,int>{i,j}==ans1.back()){
                cout<<1;
                ans1.pop_back();
            }
            else cout<<0;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}