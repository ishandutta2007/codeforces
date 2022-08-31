#include <bits/stdc++.h>

/*Ordered Set starts*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
map<int,int> freq;
int main()
{
    ordered_set s;
    s.insert(0);
    freq[0] = 1;
    int q;
    cin>>q;
    char c;
    int x;
    while(q--)
    {
        
        cin>>c>>x;
        if(c=='+')
        {
            if(freq[x] == 0)
                s.insert(x);
            freq[x]++;
        }
        if(c=='-')
        {
            if(freq[x]==1)
                s.erase(x);
            freq[x]--;
        }
        if(c=='?')
        {
            int a = 0,b = (1<<30) - 1;
            int l = s.size();
            int soa = 0,sob = l;
            
            for(int i = 29;i>=0;i--)
            {
                if(!(x&(1<<i)))
                {   
                    int _sa = s.order_of_key(a+(1<<i));
                    if(sob - _sa){
                        a+=(1<<i);
                        soa = _sa;
                    }
                    else
                    {
                        sob = _sa;
                        b = a+(1<<i);
                    }
                }
                else
                {
                    // number of elements < (a+1<<i) - number of elements < a
                    int _sb = s.order_of_key(a+(1<<i));
                    if(_sb - soa == 0){
                        a+=(1<<i);
                        soa = _sb;
                    }
                    else
                    {
                        sob = _sb;
                        b = a+(1<<i);
                    }
                }
            }
            printf("%d\n",x^a);
        }
    }
}