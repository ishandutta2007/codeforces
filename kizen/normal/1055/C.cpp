#include <bits/stdc++.h>

using namespace std;

int la, ra, ta;
int lb, rb, tb;

int gcd(int a, int b){
    return b==0? a:gcd(b, a%b);
}

int main(){
    scanf("%d %d %d %d %d %d", &la, &ra, &ta, &lb, &rb, &tb);
    int val = gcd(ta, tb);
    if(la>lb){
        swap(la, lb), swap(ra, rb), swap(ta, tb);
    }
    int A, B, ans = -1;
    A = la+(lb-la)/val*val;
    B = ra+A-la;
    ans = max(ans, min(B, rb)-max(A, lb));
    A += val, B += val;
    ans = max(ans, min(B, rb)-max(A, lb));
    if(ra>rb){
        swap(la, lb), swap(ra, rb), swap(ta, tb);
    }
    B = ra+(rb-ra)/val*val;
    A = la+B-ra;
    ans = max(ans, min(B, rb)-max(A, lb));
    A += val, B += val;
    ans = max(ans, min(B, rb)-max(A, lb));
    printf("%d", ans+1);
    return 0;
}