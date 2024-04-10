n = int(input())
a = list(map(int,input().split()))
print( 'Alice' if a.count(min(a)) <= n//2 else 'Bob' )