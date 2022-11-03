#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;int main(){int f,i,t;int ans=0;char c='\n';cin >> f >> i >> t;int *j;j = new int[i];for(int p=0;p<i;p++){j[p]=0; }for(int i0=0;i0<f;i0++){for(int i1=0;i1<i;i1++){c='\n';while(c=='\n'){cin >> c;}if(c=='Y'){j[i1]++;}}}for(int p=0;p<i;p++){if(j[p]>=t)ans++;}cout << ans;return 0;}
// kitten