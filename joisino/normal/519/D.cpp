#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef pair<ll,char> P;

map<P,int> cnt;

int n;
int like[26];
ll sum[100010];
char str[100010];

int main(){

  for( int i = 0; i < 26; i++ )
    scanf( "%d" , &like[i] );

  scanf( "%s" , str );
  n = strlen( str );

  sum[0] = like[str[0]-'a'];
  for( int i = 1; i < n; i++ )
    sum[i] = sum[i-1] + like[str[i]-'a'];

  ll ans = 0;
  for( int i = n-1; i >= 0; i-- ){
    ans += cnt[P(sum[i]+like[str[i]-'a'],str[i])];
    cnt[P(sum[i],str[i])]++;
  }

  printf( "%I64d\n" , ans );
    
  return 0;
}