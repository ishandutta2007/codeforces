#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
int n;
struct tir
{
 int x;
 int y;
 int t;
 double p;
 void scan ()
 {
   scanf ("%d%d%d%lf", &x, &y, &t, &p);
 }
 bool operator < (tir b)
 {
  return (t<b.t || ((t==b.t && x<b.x) || (t==b.t && x==b.x && y<b.y)));
 }
 long double dist (tir b)
 {
  return sqrt((long double)((b.y-y)*(b.y-y)+(b.x-x)*(b.x-x)));
 }
};
tir a[2000];
double b[2000];
bool miss (tir q, tir w)
{
 if (q.dist(w)<=(long double)(w.t-q.t))
  return 1;
 return 0;
}
int main()
{
 scanf ("%d", &n);
 int i;
 for (i=0; i<n; i++)
  a[i].scan();
 sort (a, a+n);
 int j;
 b[0]=a[0].p;
 for (i=1; i<n; i++)
 {
  b[i]=a[i].p;
  for (j=0; j<i; j++)
  {
   if (miss(a[j], a[i])==1 && b[j]+a[i].p>b[i])
    b[i]=b[j]+a[i].p;
  }
 }
 double q=0;
for (i=0; i<n; i++)
if (b[i]>q)
q=b[i];
 printf ("%.7lf", q);
 return 0;
}