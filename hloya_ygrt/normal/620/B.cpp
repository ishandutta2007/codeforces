#include <bits/stdc++.h>

using namespace std;
    int nums[10];

    int getnums(int x){
        int ans =0 ;
        while (x){
            int m = x%10;
            ans += nums[m];
            x/=10;
        }
        return ans;
    }
int main()
{
    nums[0] = 6;
    nums[1] = 2;
    nums[2] = 5;
    nums[3] = 5;
    nums[4] = 4;
    nums[5] = 5;
    nums[6] = 6;
    nums[7] = 3;
    nums[8] = 7;
    nums[9] = 6;

    int a,b;
    scanf("%d%d",&a,&b);
int ans=0;
    for (int i=a;i<=b;i++){
        ans += getnums(i);
    }

    cout<<ans;
    return 0;
}