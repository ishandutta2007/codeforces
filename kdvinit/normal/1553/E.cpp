/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int minSwapsToSort(int arr[], int n)
{
    // Create an array of pairs where first
    // element is array element and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // Sort the array by array element values to
    // get right position of every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        ans += (cycle_size - 1);
    }

    // Return result
    return ans;
}

// method returns minimum number of swap to make
// array B same as array A
int minSwapToMakeArraySame(int a[], int b[], int n)
{
    // map to store position of elements in array B
    // we basically store element to index mapping.
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[b[i]] = i;

    // now we're storing position of array A elements
    // in array B.
    for (int i = 0; i < n; i++)
        b[i] = mp[a[i]];

    /* We can uncomment this section to print modified
      b array
    for (int i = 0; i < N; i++)
        cout << b[i] << " ";
    cout << endl; */

    // returing minimum swap for sorting in modified
    // array B as final answer
    return minSwapsToSort(b, n);
}

int n, m;
bool pos(int a[], int b[])
{
    int c[n], d[n];
    for(int i=0; i<n; i++) c[i]=b[i+1];
    for(int i=0; i<n; i++) d[i]=a[i+1];
    int cnt = minSwapToMakeArraySame(c, d, n);
    if(cnt<=m) return true;
    else return false;
}

void solve()
{
    cin>>n>>m;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> ans;
    int cnt[n]={0};

    for(int i=1; i<=n; i++)
    {
        int x = i-a[i];
        if(x<0) x+=n;
        cnt[x]++;
    }

    for(int i=0; i<n; i++)
    {
        int l = n-cnt[i];
        // cout<<i<<" -> "<<cnt[i]<<" "<<l<<endl;
        if(l>(2*m)) continue;

        int b[n+1];
        for(int j=1; j<=n; j++)
        {
            int k = j+i;
            if(k>n) k-=n;
            b[k]=j;
        }
        if(pos(a, b)) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    int l = ans.size();
    cout<<l<<" ";
    if(l!=0) for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}