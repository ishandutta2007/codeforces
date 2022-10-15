/*
K.D. Vinit  |,,|

I See,
You have come here to stalk how i did this problem :)
Am I Right or Am I Right?
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, m, k;
int n2, m2;

const int N = 5e5 + 5;
int a[N], b[N];
int m_inv[N];
int gnm, lnm;

int phi(int $n)
{
    int result = $n;
    for (int i = 2; i * i <= $n; i++)
    {
        if ($n % i == 0)
        {
            while ($n % i == 0) $n /= i;
            result -= result / i;
        }
    }

    if ($n > 1) result -= result / $n;

    return result;
}

/**Takes a&b as input and Returns : The power (a,b), (a^b)%mod **/
int Power(int $a, int $b, int $mod)
{
    int $result=1; $a%=$mod;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;     $a%=$mod;     $result%=$mod;    $b/=2; }
    return $result;
}

void Get_All_m_inv()
{
    m_inv[0] = 0;
    m_inv[1] = 1;
    int phi_m = phi(m2)%m2;

    for(int i=2; i<m2; i++)
    {
        if(__gcd(i, m2)!=1) { m_inv[i]=0; continue; }
        m_inv[i] = Power(i, phi_m - 1, m2);
    }

    //for(int i=0; i<m; i++) cout<<i<<" -> "<<m_inv[i]<<endl;
}

vector<int> First_Time;

void Get_All_First()
{
    int mx = max(n, m);
    int pos[2*mx+1]={0};

    for(int i=1; i<=n; i++) pos[a[i]]=i;

    for(int i=1; i<=m; i++)
    {
        int u = pos[b[i]], v = i;
        if(u==0) continue;

        int c = v-u;
        while(c<0) c+=m;

        if(c%gnm!=0) continue;
        c/=gnm;

        int c1 = n%m;
        c1/=gnm;
        int tmp = ( c*(m_inv[c1]) )%m2;

        //cout<<c<<" "<<c1<<" "<<m_inv[c1]<<endl;

        int len = tmp*n + u;
        len%=lnm;
        if(len==0) len+=lnm;

        //cout<<u<<" "<<v<<" "<<len<<endl;

        First_Time.push_back(len);
    }

    return;
}


bool Check_Day(int day)
{
    // Returns true if less that k days angry till now
    // Else True

    int Happy = 0;

    int comp = day/lnm;
    int xtra = day%lnm;

    for(int i=0; i<First_Time.size(); i++)
    {
        Happy+=comp;
        int x = First_Time[i];
        if(xtra>=x) Happy++;
    }

    int Angry = day - Happy;

    if(Angry<k) return true;
    else return false;
}

int Get_K()
{
    Get_All_m_inv();
    Get_All_First();

    int l = 0;  // Some value definitely true
    int r = 1e18;  // Some value definitely false

    int ans = l;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(Check_Day(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    return ans+1;
}

void solve()
{
    cin>>n>>m>>k;

    gnm = __gcd(n, m);
    lnm = ( (n*m)/(gnm) );

    n2 = n/gnm;
    m2 = m/gnm;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int ans = Get_K();
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}