#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const long long infll=1000000000000000LL;

inline long long min(long long a,long long b,long long c) {
   return min(a,min(b,c));
}

inline long long solve(long long a,long long b,long long c) {
   if(b+c&1) return infll;
   return b+c-min(b,c);
}

int main(void)
{
   long long a,b,c;
   cin >> a >> b >> c;
   long long sol=min(solve(a,b,c),solve(b,c,a),solve(c,a,b));
   cout << sol << endl;
   return 0;
}