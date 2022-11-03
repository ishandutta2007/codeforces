#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const int maxn = 100003;


int main()
{
    int a[maxn]={};
    int cnt[52] = {};
    int n;
    cin >> n;
    char c;
    int ans = n,cur;
    for(int i=0;i<n;i++){
        c = '\n';
        while(c=='\n') cin >> c;
        if(c<='Z'){
            a[i] = c - 'A';
        }else{
            a[i] = c - 'a' + 26;
        }
        cnt[a[i]]++;
    }
    int k=0;
    for(int i=0;i<52;i++){
        if(cnt[i]){
            cnt[i] = 0;
            k++;
        }
    }
    int left=0,right=0;
    cnt[a[0]] = 1;
    cur = 1;
    int u;
    while(1){
        if(cur == k){
			ans = min(ans,right-left+1);
            u = --cnt[a[left]];
            left++;
            if(left==n){
                break;
            }
            if(!u){
                cur--;
            }
        }else{
            right++;
            if(right==n){
                break;
            }
            u = cnt[a[right]]++;
            if(!u){
                cur++;
            }
		}
    }
    cout << ans;
}