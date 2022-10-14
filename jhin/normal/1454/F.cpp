#include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1){num=(num%mod*i%mod)%mod;}
                    return num;
        }

        bool prime[10000001],prime2[1000001];
        void sieve(){
        for(int i=2;i<=10000000;i+=2)
        prime[i]=false,prime[i-1]=true;
        prime[2]=true;
        for(int i=3;i*i<=10000000;i+=2)
            if(prime[i])
                for(int j=i*i;j<=10000000;j+=2*i)
                    prime[j]=false;
                    }
        vector<long long>vv,vv1;

        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
       int cnt=0;
    void pfact(long long x)
    {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
    if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
    }
        int m,n,x,y,z,k,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];
int minVal(int x, int y) { return (x < y)? x: y; }

// A utility function to get the
// middle index from corner indexes.
int getMid(int s, int e) { return s + (e -s)/2; }

/* A recursive function to get the
minimum value in a given range
of array indexes. The following
are parameters for this function.

	st --> Pointer to segment tree
	index --> Index of current node in the
		segment tree. Initially 0 is
		passed as root is always at index 0
	ss & se --> Starting and ending indexes
				of the segment represented
				by current node, i.e., st[index]
	qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	// If segment of this node is a part
	// of given range, then return
	// the min of the segment
	if (qs <= ss && qe >= se)
		return st[index];

	// If segment of this node
	// is outside the given range
	if (se < qs || ss > qe)
		return INT_MAX;

	// If a part of this segment
	// overlaps with the given range
	int mid = getMid(ss, se);
	return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
				RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range
// from index qs (quey start) to
// qe (query end). It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		//cout<<"Invalid Input";
		return -1;
	}

	return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se,
								int *st, int si)
{
	// If there is one element in array,
	// store it in current node of
	// segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements,
	// then recur for left and right subtrees
	// and store the minimum of two values in this node
	int mid = getMid(ss, se);
	st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
					constructSTUtil(arr, mid+1, se, st, si*2+2));
	return st[si];
}

/* Function to construct segment tree
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[], int n)
{
	// Allocate memory for segment tree

	//Height of segment tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of segment tree
	int max_size = 2*(int)pow(2, x) - 1;

	int *st = new int[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n-1, st, 0);

	// Return the constructed segment tree
	return st;
}


        string s;
        int t,x1,y1,z1;
        bool yes;



        int main()
        {

        ios_base::sync_with_stdio(false);




	// Build segment tree from given array
//	int *st = constructST(arr, n);

	//RMQ(st, n, qs, qe);
       cin>>t;
        while(t--)
        {

          cin>>n;
          int arr[n];mx=0;
//          1 2 3 4 7 2 3 8 9 7 8 9 1 7 7 1 2 3 7
          for(int i=0;i<n;i++)
          {
              cin>>arr[i];
              mx=max(mx,arr[i]);
          }
          cnt=0;x=0;y=0;z=0;
          for(int i=0;i<n;i++)
          {
              if(arr[i]==mx&&cnt==0)cnt++,x=i+1;
            else if(arr[i]==mx&&cnt==1)cnt++,y=i+1;
            else if(arr[i]==mx&&cnt==2)cnt++,z=i+1;

          }
          //cout<<z<<"\n";
          if(z)
          {
              //if maximum number exists 3 times or more it can be solved like this
              cout<<"YES\n"<<y-1<<" 1 "<<n-y<<"\n";

          }
          else
          {


          int *st = constructST(arr, n);


          vector<int> pref,suf;x=0;y=0;
          pref.push_back(arr[0]);suf.push_back(arr[n-1]);
          for(int i=1;i<n;i++)
          {
            pref.push_back(max(pref[i-1],arr[i]));
          }
          for(int i=n-2,j=1;i>=0;i--,j++)
          {
              suf.push_back(max(suf[j-1],arr[i]));
          }
          for(int i=0;i<n;i++)
          {

             auto it=lower_bound(suf.begin(),suf.end(),pref[i]+1);
             cnt=it-suf.begin();
             int ind=n-cnt-1;
             it--;
             if(*it==pref[i]){

             if(*it==arr[ind+1]&&suf[cnt-2]==pref[i])ind++,cnt--;
             int tst=RMQ(st, n, i+1, ind);
             yes=false;
            //cout<<i+1<<" "<<n-i-1-cnt<<" "<<cnt<<" "<<tst<<"\n";
             if(tst==pref[i])
             {
                 cout<<"YES\n"<<i+1<<" "<<n-i-1-cnt<<" "<<cnt<<"\n";yes=true;
                 break;

             }
             }

          }
          if(!yes)cout<<"NO\n";



          }

        }



        return 0;
        }