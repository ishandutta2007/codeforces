#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
                solve ();
        return 0;
}
//caution: is int really int?
//#define int li
int n, k, numbers[10050];
pair <pair <int, int> , int> dob[10050];
int kolvo[20];
int ans=1000000;
int answer[10050];
int maybe[10050];
void solve ()
{
        cin>>n>>k;
        for (int i=0; i<n; i++)
        {
                scanf ("%1d", &numbers[i]);
                kolvo[numbers[i]]++;
        }
        for (int num=0; num<10; num++)
        {
                int cur=k-kolvo[num];
                if (cur<=0)
                {
                        cout<<"0\n";
                        for (int i=0; i<n; i++)
                                cout<<numbers[i];
                        return;
                }
                for (int i=0; i<n; i++)
                {
                        dob[i].second=(numbers[i]>=num)?i:(-i);
						dob[i].first.first=abs (numbers[i]-num);
						dob[i].first.second=((numbers[i]>=num)?0:1);
                }
                sort (dob, dob+n);
                int sum=0;
                for (int i=0; i<k; i++)
				{
					sum+=dob[i].first.first;
				}
                if (sum<ans)
                {
                        ans=sum;
                        for (int i=0; i<k; i++)
                                answer[abs(dob[i].second)]=num;
                        for (int i=k; i<n; i++)
                                answer[abs(dob[i].second)]=numbers[abs(dob[i].second)];
                }
				else 
					if ( sum==ans )
					{
						//cout<<sum<<"  "<<num<<endl;
						for (int i=0; i<k; i++)
                                maybe[abs(dob[i].second)]=num;
                        for (int i=k; i<n; i++)
                                maybe[abs(dob[i].second)]=numbers[abs(dob[i].second)];
						bool f=true;
						for (int i=0; i<n; i++)
							if (maybe[i]>answer[i])
							{
								f=false;
								break;
							}
							else 
								if (maybe[i]<answer[i])
								{
									f=true;
									break;
								}
						if (f)
							for (int i=0; i<n; i++)
								answer[i]=maybe[i];
					}
        }
        cout<<ans<<endl;
        for (int i=0; i<n; i++)
                cout<<answer[i];
}