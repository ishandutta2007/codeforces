#include <bits/stdc++.h>
using namespace std;
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){
        for(int a = x; a<=size; a+=a&-a){
            arr[a]+=val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum+=arr[a];
        }
        return sum;
    }
    void change(int x, int val){
        int v = query(x)-query(x-1); 
        update(x,val-v);
    }
    int query(int x, int y){//inclusive
        return query(y)-query(x-1);
    }
};
int mxn = (int)1e5+5;
int solve(vector<pair<int,int>>a, vector<pair<int,int>>b, vector<pair<int,int>>c){
    vector<int>freqc(mxn+5);
    for(pair<int,int>nxt: c){
        freqc[nxt.second]++;
    }
    BIT bit;
    BIT bit2;
    bit.init(mxn); bit2.init(mxn);
    vector<vector<int>>arr(mxn+5);
    vector<vector<int>>arr2(mxn+5);
    for(pair<int,int>nxt: a){
        arr[nxt.second].push_back(nxt.first);
        bit.update(nxt.first,1);
    }
    for(pair<int,int>nxt: b){
        arr2[nxt.second].push_back(nxt.first);
        bit2.update(nxt.first,1);
    }
    int ans = 0; int curc = 0;
    for(int i = mxn; i>=1; i--){
        curc+=freqc[i];
        for(int nxt: arr[i]){
            bit.update(nxt,-1);
        }
        for(int nxt: arr2[i]){
            bit2.update(nxt,-1);
        }
        int low = 0; int high = mxn; int mid = (low+high)/2;
        while(low+1<high){
            if(bit.query(0,mid)<=bit2.query(mid+1,mxn)){
                low = mid;
            }
            else{
                high = mid;
            }
            mid = (low+high)/2;
        }
        //cout << curc << " " << bit.query(0,low) << " " << bit2.query(high,mxn) << "\n";
        ans = max(ans,min({curc,bit.query(0,low),bit2.query(high,mxn)}));
    }
    return ans;
}
int solve2(vector<pair<int,int>>a,vector<pair<int,int>>b, vector<pair<int,int>>c){
    vector<int>freqc(mxn+5);
    for(pair<int,int>nxt: c){
        freqc[nxt.first]++;
    }
    BIT bit;
    BIT bit2;
    bit.init(mxn);
    bit2.init(mxn);
    vector<vector<int>>arr(mxn+5);
    vector<vector<int>>arr2(mxn+5);
    for(pair<int,int>nxt: a){
        arr[nxt.first].push_back(nxt.first);
        bit.update(nxt.first,1);
    }
    for(pair<int,int>nxt: b){
        arr2[nxt.first].push_back(nxt.first);
        bit2.update(nxt.first,1);
    }
    int ans = 0;
    int curc = 0;
    for(int i = mxn; i>=1; i--){
        curc+=freqc[i];
        for(int nxt: arr[i]){
            bit.update(nxt,-1);
        }
        for(int nxt: arr2[i]){
            bit2.update(nxt,-1);
        }
        int low = 0; int high = mxn; int mid = (low+high)/2;
        while(low+1<high){
            if(bit.query(0,mid)<=bit2.query(mid+1,mxn)){
                low = mid;
            }
            else{
                high = mid;
            }
            mid = (low+high)/2;
        }
        //cout << curc << " " << bit.query(0,low) << " " << bit2.query(high,mxn) << "\n";
        ans = max(ans,min({curc,bit.query(0,low),bit2.query(high,mxn)}));
    }
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>>arr(n+1);
    vector<int>sortedx;
    vector<int>sortedy;
    sortedx.push_back(-(int)2e9);
    sortedy.push_back(-(int)2e9);
    vector<int>val(n+1);
    for(int i = 1; i<=n; i++){
        int x,y,c;
        cin >> x >> y >> c;
        arr[i] = {x,y};
        val[i] = c;
        sortedx.push_back(x);
        sortedy.push_back(y);
    }
    sort(sortedx.begin(),sortedx.end());
    sort(sortedy.begin(),sortedy.end());
    for(int i = 1; i<=n; i++){
        arr[i].first = lower_bound(sortedx.begin(),sortedx.end(),arr[i].first)-sortedx.begin();
        arr[i].second = lower_bound(sortedy.begin(),sortedy.end(),arr[i].second)-sortedy.begin();
    }
    int ans = 0;
    vector<int>perm = {1,2,3};
    do{
        vector<pair<int,int>>a;
        vector<pair<int,int>>b;
        vector<pair<int,int>>c;
        for(int i = 1; i<=n; i++){
            if(val[i]==perm[0]){
                a.push_back(arr[i]);
            }
            if(val[i]==perm[1]){
                b.push_back(arr[i]);
            }
            if(val[i]==perm[2]){
                c.push_back(arr[i]);
            }
        }
        ans = max(ans,solve(a,b,c));
        ans = max(ans,solve2(a,b,c));
        for(int i = 0; i<a.size(); i++){
            a[i].first = mxn-3-a[i].first;
            a[i].second = mxn-3-a[i].second;
        }
        for(int i = 0; i<b.size(); i++){
            b[i].first = mxn-3-b[i].first;
            b[i].second = mxn-3-b[i].second;
        }
        for(int i = 0; i<c.size(); i++){
            c[i].first = mxn-3-c[i].first;
            c[i].second = mxn-3-c[i].second;
        }
        ans = max(ans,solve(a,b,c));
        for(int i = 0; i<a.size(); i++){
            swap(a[i].first,a[i].second);
        }
        for(int i = 0; i<b.size(); i++){
            swap(b[i].first,b[i].second);
        }
        for(int i = 0; i<c.size(); i++){
            swap(c[i].first,c[i].second);
        }
        ans = max(ans,solve(a,b,c));
        ans = max(ans,solve2(a,b,c));
        for(int i = 0; i<a.size(); i++){
            a[i].first = mxn-3-a[i].first;
            a[i].second = mxn-3-a[i].second;
        }
        for(int i = 0; i<b.size(); i++){   
            b[i].first = mxn-3-b[i].first;
            b[i].second = mxn-3-b[i].second;
        }
        for(int i = 0; i<c.size(); i++){
            c[i].first = mxn-3-c[i].first;
            c[i].second = mxn-3-c[i].second;
        }
        ans = max(ans,solve(a,b,c));
        //cerr << "nae\n";
       // break;
    }
    while(next_permutation(perm.begin(),perm.end()));
    cout << ans*3 << "\n";
    return 0;
}