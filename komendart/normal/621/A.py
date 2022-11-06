def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    
    cnt = 0
    mi = 10 ** 9
    for i in a:
        if i % 2 == 1:
            cnt ^= 1
            mi = min(mi, i)
    
    if not cnt:
        mi = 0
    print(sum(a) - mi)
    
    
main()