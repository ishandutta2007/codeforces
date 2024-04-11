def main():
    n, m = [int(i) for i in input().split()]
    
    day = 1
    while n > 0:
        if day % m == 0:
            n += 1
        n -= 1
        day += 1
    
    print(day - 1)


main()