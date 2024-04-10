k,n,w=map(int,input().split())
w=(w+1)*w//2*k
if w>n:
    print(w-n)
else:
    print(0)