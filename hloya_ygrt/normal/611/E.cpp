#include <bits\stdc++.h>


using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long



const int maxn = 2e5+500;


int a[3];
    multiset < int > events;
    multiset < int >::iterator myit;



void getf ( int y ) {
     if (events.empty())
    return;
    myit = events.upper_bound( a[y] );
    if (events.empty())
    return;
    if ( myit == events.begin() )
        return;

    if ( !events.empty() )
       {
            myit--;
            events.erase( myit );
       }
}
bool _repl ( int a, int b ) {
    if (a<b) return 0;
    return 1;
}
void getdou ( int y1, int y2 )
{
    multiset < int >::iterator myit2,myit3,myit1;
   if (events.empty())
    return;
    myit1 = events.upper_bound(a[y1]);
    myit2 = events.upper_bound(a[y2]);
   if (events.empty())
    return;
    if (myit1==events.begin())
    {   if (events.empty())
    return;
        myit3 = events.upper_bound( a[y2] + a[y1] );
   if (events.empty())
    return;
        if (!( myit3 == events.begin()))
    {

     if (!events.empty())
           {
                myit3--;
                events.erase( myit3 );
                return;
           }}
           else
        return;
    }
   if (events.empty())
    return;
    if ( myit2 == events.begin() )
{if (events.empty())
    return;
        myit3 = events.upper_bound( a[y2] + a[y1] );
   if (events.empty())
    return;
    if (!events.empty())
        {if (!( myit3 == events.begin()))

        {



        myit3--;
        events.erase( myit3 );
        return;
        }
        else return;}
    }

    if ( events.empty() )
        return;

    myit1--;    if ( events.empty() )
        return;
if (events.empty())
    return;
    myit2--;

    if ( myit1 == myit2 ) {
            if (events.empty())
    return;
        if ( myit1 == events.begin() ) {
            events.erase( myit1 );
            return;
        }
        myit1--;
    } if ( !events.empty() )
    events.erase( myit1 );
    if ( !events.empty() )
    events.erase( myit2 );
}

void init(int n)
{
    for (int j=0;j<n;j++)
    {
        int x;
        scanf("%d",&x);
        events.insert(x);
    }
    sort(a,a+3);
}

multiset < int >::iterator get()
{
    if (events.empty())
        return events.end();
    multiset < int >::iterator ans=events.end();
            ans--;
            return ans;
}

void _delete()
{
            myit = get();
            if ( !events.empty() ) events.erase(myit);

            if ( !events.empty() ) {
                myit = get();
                events.erase(myit);
            }

            if ( !events.empty() ) {
                myit = get();
                events.erase(myit);
            }
}

void bad()
{
    printf ( "-1\n" );
    exit(0);
}

int main()
{
    int n;
    scanf ("%d",&n);
    scanf ("%d %d %d",a,a+1,a+2);

    init(n);

    int a12=a[0]+a[1],a23=a[1]+a[2],a13=a[0]+a[2],a123=a[0]+a[1]+a[2];
    int ans =0;

    while (!events.empty()) {

        int i=*events.rbegin();
        if ( a[0] >= i ) {

            _delete();

            ans++;
            continue;
        }

        if ( _repl(a[1],i) )
        {
 if ( !events.empty() )
            events.erase( events.find( i ) );
            getdou( 0, 2 );
            ans++;
            continue;
        }
        if ( _repl( a[2], i ) ){
         if ( !events.empty() )
            {events.erase(events.find( i ) );
            getdou( 0, 1 );
            ans++;
            continue;
            }
        }
        if ( _repl(a12,i) )
        { if ( !events.empty() )
        {


            events.erase(events.find(i) );
            getf(2);
            ans++;
            continue;
}        }
        if ( _repl(a13,i) )



        { if ( !events.empty() )
            events.erase(events.find(i) );
            getf(1);
            ans++;
            continue;
        }
        if ( _repl( a23, i ) )
        { if ( !events.empty() )
            events.erase(events.find(i));
            getf( 0 );
            ans++;
            continue;
        }
        if ( _repl(a123, i ) )
        { if ( !events.empty() )
            events.erase(events.find(i));
            ans++;
            continue;
        }
        bad();
    }
    printf ( "%d", ans );
    return 0;
}