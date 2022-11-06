def main():
    n, m = [int(i) for i in input().split()]
    
    if min(n, m) % 2 == 0:
        print("Malvika")
    else:
        print("Akshat")

main()