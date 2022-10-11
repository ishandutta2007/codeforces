n=int(input())
a=list(map(int,input().split()))[1:]
a+=list(map(int,input().split()))[1:]
if len(set(a))==n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")