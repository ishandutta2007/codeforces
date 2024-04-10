#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define mod 1000000007
#define pii pair <int , int>
#define f first
#define s second
#define pb push_back
#define ll long long
#define sz (2000)



int n,m;
string s[sz];
int ns;
bool ok[sz];
bool check(int x){
   for (int i=1;i<n; i++)
   if (s[i][x]< s[i-1][x]&&!ok[i])  return 0;
   for (int i=1; i<n;i++)
   if (s[i][x]>s[i-1][x]) ok[i]=1;
   return 1;
}

int main(){
 cin >>	 n>>m;
 for (int i=0; i<n;i++){
  cin >> s[i];
 }
 for (int i=0;i<m;i++) {
   if (!check(i)) ns++;
 }
 cout<<ns;
 return 0;
}