def main():
    n = int(input())
    w = sum(int(i) for i in input().split())
    print(w / n)

main()