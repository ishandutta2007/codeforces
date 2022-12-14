#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int N;
int arr[NS];
int A[NS], B[NS];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%1d", arr + i);
    }
    if(N % 2 == 0){
        int pos = N / 2 + 1;
        while(!arr[pos]){
            --pos;
        }
        int val = pos - 1;
        for(int i = N, j = 1; i >= pos; --i, ++j){
            A[j] += arr[i];
            if(val - (N - i) >= 1){
                A[j] += arr[val - (N - i)];
            }
            if(A[j] > 9){
                ++A[j + 1]; A[j] -= 10;
            }
        }
        pos = N / 2 + 1;
        while(!arr[pos]){
            ++pos;
        }
        val = pos - 1;
        for(int i = val, j = 1; i >= 1; --i, ++j){
            B[j] += arr[i];
            if(N - (val - i) > val){
                B[j] += arr[N - (val - i)];
            }
            if(B[j] > 9){
                ++B[j + 1]; B[j] -= 10;
            }
        }
        int f;
        for(int i = NS - 1; i >= 1; --i){
            if(A[i] < B[i]){
                f = 1; break;
            }
            if(A[i] > B[i]){
                f = 2; break;
            }
        }
        if(f == 1){
            int j = NS - 1;
            while(!A[j]){
                --j;
            }
            while(j >= 1){
                printf("%d", A[j]); --j;
            }
            puts(""); return 0;
        }
        int j = NS - 1;
        while(!B[j]){
            --j;
        }
        while(j >= 1){
            printf("%d", B[j]); --j;
        }
        puts(""); return 0;
    }
    else{
        int pos = N / 2 + 1;
        while(!arr[pos]){
            --pos;
        }
        int val = pos - 1;
        for(int i = N, j = 1; i >= pos; --i, ++j){
            A[j] += arr[i];
            if(val - (N - i) >= 1){
                A[j] += arr[val - (N - i)];
            }
            if(A[j] > 9){
                ++A[j + 1]; A[j] -= 10;
            }
        }
        pos = N / 2 + 2;
        while(!arr[pos]){
            ++pos;
        }
        val = pos - 1;
        for(int i = val, j = 1; i >= 1; --i, ++j){
            B[j] += arr[i];
            if(N - (val - i) > val){
                B[j] += arr[N - (val - i)];
            }
            if(B[j] > 9){
                ++B[j + 1]; B[j] -= 10;
            }
        }
        int f;
        for(int i = NS - 1; i >= 1; --i){
            if(A[i] < B[i]){
                f = 1; break;
            }
            if(A[i] > B[i]){
                f = 2; break;
            }
        }
        if(f == 1){
            int j = NS - 1;
            while(!A[j]){
                --j;
            }
            while(j >= 1){
                printf("%d", A[j]); --j;
            }
            puts(""); return 0;
        }
        int j = NS - 1;
        while(!B[j]){
            --j;
        }
        while(j >= 1){
            printf("%d", B[j]); --j;
        }
        puts(""); return 0;
    }
    return 0;
}