k,n,w = map(int,raw_input().strip().split())
print max(0, w*(w+1)/2*k - n)