n = int(input())
print( 0 if n&1 else 1<<(n>>1) )