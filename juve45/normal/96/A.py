
x=input();

k=1;
ok=0
for i in range(1, len(x)) :
    if x[i]==x[i-1] :
        k=k+1;
        if(k==7):
            ok=1
    else:
        k=1
if(ok) :
    print("YES")
else:
    print("NO")