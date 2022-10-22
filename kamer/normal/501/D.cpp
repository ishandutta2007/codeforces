#include<iostream>
using namespace std;

int aib[3][200003];

int prev(int i){
    return i & (i-1);
}

int next(int i){
    return  (i << 1) - (i & (i-1) ); 
}

int sum(int t,int i){
    int sol = 0;
    while (i>0){
        sol += aib[t][i];
        i = prev(i);
    }

    return sol;
}

int n,t;

void update(int t,int i){
    while (i < n+1){
        aib[t][i]++;
        i = next(i);
    }
}

int sir[2][200002], useful[2][200002];
int useSol[200002], sol[200002];

int query(int k){
    
    int r=n,l=n,mid;
    int sol = sum(2,n), s;
    while ((l-1-sol) >= k){
        sol -= aib[2][l];
        r = l;
        l = prev(l);
    
    }
    

    while (r-l > 1){
        mid = (r+l) / 2;
        s = aib[2][mid];
        if (mid - 1 - sol - s >= k) r = mid;
        else {l = mid; sol += s;}
    }
    
    if (l-1-sol == k) return l;
    else return r;
}

int main(void){
    cin >> n;
    int i;

    for(t=0;t<=1;t++){
        for(i=1;i<=n;i++){
            cin >> sir[t][i];
            useful[t][i] = sir[t][i] - sum( t, sir[t][i]+1 );
            update(t,sir[t][i]+1);
        }
    }
    
    int carry = 0;
    for(i=n;i>=1;i--){
        if (useful[0][i] + useful[1][i] + carry>= (n-i+1)){
            useSol[i] = (useful[0][i] + useful[1][i] + carry) - (n-i+1);
            carry = 1;
        }
        else{
            useSol[i] = useful[0][i] + useful[1][i] + carry;
            carry = 0;
        }
    }
    for(i=1;i<=n;i++){
        sol[i] = query(useSol[i]) - 1;
        update(2,sol[i] + 1);
        cout << sol[i] << " ";
    }



}