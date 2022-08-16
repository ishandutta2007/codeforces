#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
#define For(i,n) for(int i=0;i<n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define F first
#define S second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
const int MaxN=500500;
const int MaxQ=800;
int arr[MaxN];
signed main(){
    fio;
    int n,k;
    cin>>n>>k;
    For(i,n){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sub=0;
    int i=0,cnt=0;
    while (cnt<k){
        if (i>n-1) {cout<<0<<endl; cnt++;}
        else {
            if (arr[i]<=sub) {i++;continue;}
            else {cout<<arr[i]-sub<<endl; sub=arr[i];
            cnt++;
            i++;
            }
    }}
}