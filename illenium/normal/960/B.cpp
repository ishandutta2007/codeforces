#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 1005;  
long long number1[maxn], number2[maxn], ans[maxn];  
  
bool cmp(long long a, long long b){  
    return abs(a) < abs(b);  
}  
  
int main(){  
    int n, k1, k2;  
    while(cin>>n>>k1>>k2){  
        memset(ans, 0, sizeof(ans));  
        memset(number2, 0, sizeof(number2));  
        memset(number1, 0, sizeof(number1));  
        for(int i = 0; i < n; i++){  
            cin>>number1[i];  
        }  
        for(int i = 0; i < n; i++){  
            cin>>number2[i];   
        }  
        for(int i = 0; i < n; i++){  
            ans[i] = abs(number1[i]-number2[i]);  
        }  
        sort(ans, ans+n, cmp);  
        int t = k1 + k2;  
        while(t){  
            if(ans[n-1] < 0){  
                ans[n-1]++;  
            }  
            else{  
                ans[n-1]--;  
            }  
            t--;  
            sort(ans, ans+n, cmp);  
        }  
        long long sum = 0;  
        for(int i = 0; i < n; i++){  
            sum += ans[i]*ans[i];  
        }  
        cout<<sum<<endl;  
    }  
}