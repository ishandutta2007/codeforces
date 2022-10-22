#include <bits/stdc++.h>

using namespace std;

vector<long long int> nums;

int main() {
    bool mustplus=true;
    long long int n, ans=0, ml=0;
    char c;
    cin >> n;
    nums.push_back(1);
    while(n--) {
        cin >> c;
        if(!mustplus) {
            long long int k=0;
            for(int a=0; a<nums.size(); a++) {
                nums[a]+=k;
                k=nums[a];
                if(nums[a]>1'000'000'007) nums[a]%=1000000007;
                if(k>1000000007) k%=1000000007;
            }
        }
        if(c=='f') {
            ml++;
            mustplus=true;
            nums.push_back(0);
        }
        else {
            mustplus=false;
        }
    }
    for(int a=0; a<nums.size(); a++) {
        //cout << nums[a] << ' ';
        ans+=nums[a];
        if(ans>1000000007) ans%=1000000007;
    }
    cout << ans;
}