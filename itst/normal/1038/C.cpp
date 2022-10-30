#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c)){
        a = (a << 3) + (a << 1) + (c ^ '0');
        c = getchar();
    }
    return a;
}

int numA[100001] , numB[100001];
int main()
{
    long long sum = 0;
    int N = read();
    for(int i = 1 ; i <= N ; i++)
        numA[i] = read();
    for(int i = 1 ; i <= N ; i++)
        numB[i] = read();
    sort(numA + 1 , numA + N + 1);
    sort(numB + 1 , numB + N + 1);
    int dirA = N , dirB = N;
    for(int i = 1 ; i <= N ; i++){
        if(numA[dirA] >= numB[dirB])
            sum += numA[dirA--];
        else
            dirB--;
        if(numB[dirB] >= numA[dirA])
            sum -= numB[dirB--];
        else
            dirA--;
    }
    cout <<  sum;
 	return 0;
}