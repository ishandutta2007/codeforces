def f(a,b):
    if a==1 or b==1:
        return 1
    return f(a-1,b)+f(b-1,a)
n=int(input())
print(f(n,n))