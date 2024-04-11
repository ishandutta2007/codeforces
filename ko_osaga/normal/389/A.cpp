    #import<iostream>  
    int g(int a,int b){return a%b?g(b,a%b):b;}int n,x,t,i;main(){std::cin>>n>>x;for(;++i<n;)std::cin>>t,x=g(x,t);std::cout<<x*n;}