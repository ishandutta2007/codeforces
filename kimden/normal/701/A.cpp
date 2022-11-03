#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007

struct pred{
    bool operator()(pair<int,int> &x,pair<int,int> &y){
        return x.first<y.first;
    }
};

int main()
{
    int n;
    cin >> n;
    deque<pair<int,int>> q;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        q.push_back(make_pair(a,i+1));
    }
    sort(q.begin(),q.end());
    while(!q.empty()){
        cout << q.front().second << " " << q.back().second << "\n";
        q.pop_front();
        q.pop_back();
    }
}