#include<bits/stdc++.h>
using namespace std;
int num[110];
int main(){
    int N , sum = 0;
    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        char c = getchar();
        while(!isdigit(c))
            c = getchar();
        num[i] = c - '0';
        sum += num[i]; 
    }
    if(sum == 0){
        puts("YES");
        return 0;
    }
    for(int j = 1 ; j < sum ; ++j)
        if(sum % j == 0){
            int cur = 0;
            bool f = 1;
            for(int k = 1 ; f && k <= N ; ++k)
                if(num[k] > j)
                    f = 0;
                else
                    if(cur + num[k] > j)
                        if(cur != j)
                            f = 0;
                        else
                            cur = num[k];
                    else
                        cur += num[k];
            if(f && cur == j){
                puts("YES");
                return 0;
            }
        }
    puts("NO");
    return 0;
}