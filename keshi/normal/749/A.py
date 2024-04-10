n=int(input())
print(n//2)
s=['2']*(n//2)
if n%2:
    s[-1]='3'
print(*s)