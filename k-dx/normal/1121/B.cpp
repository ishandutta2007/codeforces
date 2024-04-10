#include <bits/stdc++.h>
using namespace std;

int n;
int sweets[1005];

int main () {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &sweets[i]);
    
    sort(sweets, sweets + n);
    
    int best = 0;
    for(int i = 1; i < 200001; i++){
        int pocz = 0,
            kon = n-1,  
            result = 0;
    
        while(pocz < kon){
            int sum = sweets[pocz] + sweets[kon];
            if(sum < i){
                pocz++;
            }
            else if(sum == i){
                pocz++;
                kon--;
                result++;
            }
            else if(sum > i){
                kon--;
            }
        }

        best = max(best, result);
    }

    printf("%d\n", best);

    return 0;
}